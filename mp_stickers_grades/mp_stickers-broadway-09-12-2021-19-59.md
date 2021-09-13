


## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
StickerSheet.cpp:10:11: fatal error: no viable conversion from 'Image *' to 'Image'
    Image img = new Image();
          ^     ~~~~~~~~~~~
./Image.h:12:7: note: candidate constructor (the implicit copy constructor) not viable: no known conversion from 'Image *' to 'const Image &' for 1st argument; dereference the argument with *
class Image : public PNG {
      ^
./Image.h:12:7: note: candidate constructor (the implicit move constructor) not viable: no known conversion from 'Image *' to 'Image &&' for 1st argument
1 error generated.
make: *** [.objs/StickerSheet.o] Error 1

```
```
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c Image.cpp -o .objs/Image.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c StickerSheet.cpp -o .objs/StickerSheet.o

```


---

This report was generated for **waltert3** using **3871ce5b197944a336ab2fb8fcfe5fd52607a1eb** (latest commit as of **September 12th 2021, 8:00 pm**)
