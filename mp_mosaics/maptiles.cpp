/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
    MosaicCanvas *canvas = new MosaicCanvas(theSource.getRows(), theSource.getColumns());
    const int dim = 3;
    vector<Point<dim> > points;
    vector<TileImage>::iterator it = theTiles.begin();
    vector<TileImage>::iterator end = theTiles.end();
    map<Point<dim>, TileImage*> map;
    while(it != end) {
        LUVAPixel p = it->getAverageColor();
        Point<dim> p2 = convertToXYZ(p);
        points.push_back(p2);
        map[p2] = & *it;
        ++it;
    }
    KDTree<dim> color(points);
    for(int i = 0; i < canvas->getRows(); i++) {
        for(int j = 0; j < canvas->getColumns(); j++) {
            LUVAPixel pixel = theSource.getRegionColor(i, j);
            Point<dim> p = convertToXYZ(pixel);
            Point<dim> p2 = color.findNearestNeighbor(p);
            TileImage *tile = map[p2];
            canvas->setTile(i, j, tile);
        }
    }

    return canvas;
}

