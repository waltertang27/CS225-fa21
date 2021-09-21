


## Score: 0/0 (0.00%)


### ✗ - [0/0] - Output from `make`

- **Points**: 0 / 0

```
StickerSheet.cpp:237:27: fatal error: reference to overloaded function could not be resolved; did you mean to call it?
  for(unsigned i = 0; i < max; i++) {
                          ^~~
/usr/local/bin/../include/c++/v1/algorithm:2709:1: note: possible target for call
max(const _Tp& __a, const _Tp& __b, _Compare __comp)
^
/usr/local/bin/../include/c++/v1/algorithm:2717:1: note: possible target for call
max(const _Tp& __a, const _Tp& __b)
^
/usr/local/bin/../include/c++/v1/algorithm:2727:1: note: possible target for call
max(initializer_list<_Tp> __t, _Compare __comp)
^
/usr/local/bin/../include/c++/v1/algorithm:2735:1: note: possible target for call
max(initializer_list<_Tp> __t)
^
1 error generated.
make: *** [.objs/StickerSheet.o] Error 1

```
```
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c Image.cpp -o .objs/Image.o
clang++  -std=c++14 -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c StickerSheet.cpp -o .objs/StickerSheet.o

```


---

This report was generated for **waltert3** using **7192757480419efb3c42acd8a91d844d6451ca7a** (latest commit as of **September 20th 2021, 11:23 pm**)
