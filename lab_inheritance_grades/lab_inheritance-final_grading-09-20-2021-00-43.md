---

This report was generated for **waltert3** using **68440e4500954444bdee510febefa5527bc171c2** (latest commit as of **September 19th 2021, 11:59 pm**)

---




## Score: 60/90 (66.67%)


### ✓ - [0/0] - Output from `make`

- **Points**: 0 / 0


```
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor circle.cpp -o .objs/circle.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor flower.cpp -o .objs/flower.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor line.cpp -o .objs/line.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor rectangle.cpp -o .objs/rectangle.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor shape.cpp -o .objs/shape.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor triangle.cpp -o .objs/triangle.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor truck.cpp -o .objs/truck.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor vector2.cpp -o .objs/vector2.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor cs225/HSLAPixel.cpp -o .objs/cs225/HSLAPixel.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor cs225/PNG.cpp -o .objs/cs225/PNG.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor cs225/lodepng/lodepng.cpp -o .objs/cs225/lodepng/lodepng.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor tests/tests.cpp -o .objs/tests/tests.o
clang++  -std=c++1y -stdlib=libc++ -O0 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -MMD -MP -g -c -Wno-delete-non-virtual-dtor cs225/catch/catchmain.cpp -o .objs/cs225/catch/catchmain.o
clang++ .objs/circle.o .objs/flower.o .objs/line.o .objs/rectangle.o .objs/shape.o .objs/triangle.o .objs/truck.o .objs/vector2.o .objs/cs225/HSLAPixel.o .objs/cs225/PNG.o .objs/cs225/lodepng/lodepng.o .objs/tests/tests.o .objs/cs225/catch/catchmain.o  -std=c++1y -stdlib=libc++ -lc++abi -o test

```


### ✓ - [10/10] - test_virtual_perim

- **Points**: 10 / 10





### ✓ - [10/10] - test_virtual_area

- **Points**: 10 / 10





### ✓ - [20/20] - test_destructor

- **Points**: 20 / 20

```
==73== Memcheck, a memory error detector
==73== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==73== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==73== Command: ./test -r xml "test_destructor"
==73== 
==73== 
==73== HEAP SUMMARY:
==73==     in use at exit: 0 bytes in 0 blocks
==73==   total heap usage: 1,667 allocs, 1,667 frees, 216,576 bytes allocated
==73== 
==73== All heap blocks were freed -- no leaks are possible
==73== 
==73== For counts of detected and suppressed errors, rerun with: -v
==73== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```



### ✓ - [20/20] - test_constructor

- **Points**: 20 / 20





### ✗ - [0/10] - test_pure_virtual

- **Points**: 0 / 10

```
==76== Memcheck, a memory error detector
==76== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==76== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==76== Command: ./test -r xml "test_pure_virtual"
==76== 
==76== 
==76== HEAP SUMMARY:
==76==     in use at exit: 616 bytes in 10 blocks
==76==   total heap usage: 1,728 allocs, 1,718 frees, 1,757,183 bytes allocated
==76== 
==76== 64 bytes in 1 blocks are definitely lost in loss record 6 of 10
==76==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==76==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==76==    by 0x40C780: Truck::Truck(Vector2 const&) (truck.cpp:37)
==76==    by 0x42BAC1: ____C_A_T_C_H____T_E_S_T____8() (tests.cpp:115)
==76==    by 0x460CE2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==76==    by 0x451436: Catch::TestCase::invoke() const (catch.hpp:10793)
==76==    by 0x45136C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==76==    by 0x44D8C6: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==76==    by 0x44BE9E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==76==    by 0x455236: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==76==    by 0x453ED2: Catch::Session::runInternal() (catch.hpp:10149)
==76==    by 0x453B9A: Catch::Session::run() (catch.hpp:10106)
==76== 
==76== 64 bytes in 1 blocks are definitely lost in loss record 7 of 10
==76==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==76==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==76==    by 0x40C86A: Truck::Truck(Vector2 const&) (truck.cpp:39)
==76==    by 0x42BAC1: ____C_A_T_C_H____T_E_S_T____8() (tests.cpp:115)
==76==    by 0x460CE2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==76==    by 0x451436: Catch::TestCase::invoke() const (catch.hpp:10793)
==76==    by 0x45136C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==76==    by 0x44D8C6: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==76==    by 0x44BE9E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==76==    by 0x455236: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==76==    by 0x453ED2: Catch::Session::runInternal() (catch.hpp:10149)
==76==    by 0x453B9A: Catch::Session::run() (catch.hpp:10106)
==76== 
==76== 64 bytes in 1 blocks are definitely lost in loss record 8 of 10
==76==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==76==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==76==    by 0x40C96C: Truck::Truck(Vector2 const&) (truck.cpp:43)
==76==    by 0x42BAC1: ____C_A_T_C_H____T_E_S_T____8() (tests.cpp:115)
==76==    by 0x460CE2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==76==    by 0x451436: Catch::TestCase::invoke() const (catch.hpp:10793)
==76==    by 0x45136C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==76==    by 0x44D8C6: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==76==    by 0x44BE9E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==76==    by 0x455236: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==76==    by 0x453ED2: Catch::Session::runInternal() (catch.hpp:10149)
==76==    by 0x453B9A: Catch::Session::run() (catch.hpp:10106)
==76== 
==76== 64 bytes in 1 blocks are definitely lost in loss record 9 of 10
==76==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==76==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==76==    by 0x40CAAF: Truck::Truck(Vector2 const&) (truck.cpp:46)
==76==    by 0x42BAC1: ____C_A_T_C_H____T_E_S_T____8() (tests.cpp:115)
==76==    by 0x460CE2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==76==    by 0x451436: Catch::TestCase::invoke() const (catch.hpp:10793)
==76==    by 0x45136C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==76==    by 0x44D8C6: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==76==    by 0x44BE9E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==76==    by 0x455236: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==76==    by 0x453ED2: Catch::Session::runInternal() (catch.hpp:10149)
==76==    by 0x453B9A: Catch::Session::run() (catch.hpp:10106)
==76== 
==76== 360 (40 direct, 320 indirect) bytes in 1 blocks are definitely lost in loss record 10 of 10
==76==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==76==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==76==    by 0x40C745: Truck::Truck(Vector2 const&) (truck.cpp:35)
==76==    by 0x42BAC1: ____C_A_T_C_H____T_E_S_T____8() (tests.cpp:115)
==76==    by 0x460CE2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==76==    by 0x451436: Catch::TestCase::invoke() const (catch.hpp:10793)
==76==    by 0x45136C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==76==    by 0x44D8C6: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==76==    by 0x44BE9E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==76==    by 0x455236: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==76==    by 0x453ED2: Catch::Session::runInternal() (catch.hpp:10149)
==76==    by 0x453B9A: Catch::Session::run() (catch.hpp:10106)
==76== 
==76== LEAK SUMMARY:
==76==    definitely lost: 296 bytes in 5 blocks
==76==    indirectly lost: 320 bytes in 5 blocks
==76==      possibly lost: 0 bytes in 0 blocks
==76==    still reachable: 0 bytes in 0 blocks
==76==         suppressed: 0 bytes in 0 blocks
==76== 
==76== For counts of detected and suppressed errors, rerun with: -v
==76== ERROR SUMMARY: 5 errors from 5 contexts (suppressed: 0 from 0)

```



### ✗ - [0/20] - test_slicing

- **Points**: 0 / 20

```
==78== Memcheck, a memory error detector
==78== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==78== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==78== Command: ./test -r xml "test_slicing"
==78== 
==78== 
==78== HEAP SUMMARY:
==78==     in use at exit: 264 bytes in 7 blocks
==78==   total heap usage: 1,794 allocs, 1,787 frees, 1,759,556 bytes allocated
==78== 
==78== 64 bytes in 1 blocks are definitely lost in loss record 5 of 7
==78==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==78==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==78==    by 0x407A35: Flower::Flower(Vector2 const&) (flower.cpp:36)
==78==    by 0x42BDA7: ____C_A_T_C_H____T_E_S_T____10() (tests.cpp:134)
==78==    by 0x460CE2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==78==    by 0x451436: Catch::TestCase::invoke() const (catch.hpp:10793)
==78==    by 0x45136C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==78==    by 0x44D8C6: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==78==    by 0x44BE9E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==78==    by 0x455236: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==78==    by 0x453ED2: Catch::Session::runInternal() (catch.hpp:10149)
==78==    by 0x453B9A: Catch::Session::run() (catch.hpp:10106)
==78== 
==78== 64 bytes in 1 blocks are definitely lost in loss record 6 of 7
==78==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==78==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==78==    by 0x407A94: Flower::Flower(Vector2 const&) (flower.cpp:39)
==78==    by 0x42BDA7: ____C_A_T_C_H____T_E_S_T____10() (tests.cpp:134)
==78==    by 0x460CE2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==78==    by 0x451436: Catch::TestCase::invoke() const (catch.hpp:10793)
==78==    by 0x45136C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==78==    by 0x44D8C6: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==78==    by 0x44BE9E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==78==    by 0x455236: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==78==    by 0x453ED2: Catch::Session::runInternal() (catch.hpp:10149)
==78==    by 0x453B9A: Catch::Session::run() (catch.hpp:10106)
==78== 
==78== 136 (64 direct, 72 indirect) bytes in 1 blocks are definitely lost in loss record 7 of 7
==78==    at 0x4C29EA3: malloc (vg_replace_malloc.c:309)
==78==    by 0x40475CB: operator new(unsigned long) (in /usr/local/lib/libc++abi.so.1.0)
==78==    by 0x407BB9: Flower::Flower(Vector2 const&) (flower.cpp:44)
==78==    by 0x42BDA7: ____C_A_T_C_H____T_E_S_T____10() (tests.cpp:134)
==78==    by 0x460CE2: Catch::TestInvokerAsFunction::invoke() const (catch.hpp:10892)
==78==    by 0x451436: Catch::TestCase::invoke() const (catch.hpp:10793)
==78==    by 0x45136C: Catch::RunContext::invokeActiveTestCase() (catch.hpp:9658)
==78==    by 0x44D8C6: Catch::RunContext::runCurrentTest(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >&) (catch.hpp:9622)
==78==    by 0x44BE9E: Catch::RunContext::runTest(Catch::TestCase const&) (catch.hpp:9408)
==78==    by 0x455236: Catch::(anonymous namespace)::runTests(std::__1::shared_ptr<Catch::Config> const&) (catch.hpp:9948)
==78==    by 0x453ED2: Catch::Session::runInternal() (catch.hpp:10149)
==78==    by 0x453B9A: Catch::Session::run() (catch.hpp:10106)
==78== 
==78== LEAK SUMMARY:
==78==    definitely lost: 192 bytes in 3 blocks
==78==    indirectly lost: 72 bytes in 4 blocks
==78==      possibly lost: 0 bytes in 0 blocks
==78==    still reachable: 0 bytes in 0 blocks
==78==         suppressed: 0 bytes in 0 blocks
==78== 
==78== For counts of detected and suppressed errors, rerun with: -v
==78== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)

```



---