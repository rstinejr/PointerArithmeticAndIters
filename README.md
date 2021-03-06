# Pointer Arithmentic and Iterators

## Intro

This project demonstrates elementary pointer arithmetic in C/C++ and shows its relationship
to Standard Template Library iterators.

I blame it on the fact that I program in multiple languages, but it seems that every time 
I want to initialize a vector or list, I have to hit Google.  My hope is that this project 
will cement that knowledge for me once and for all, but if not, at least I'll have a handy
cheat sheet.

## Building

I developed this project on 64-bit Linux Mint 17.2.

The compiler was g++ (Ubuntu 4.9.3-8ubuntu2~14.04) 4.9.3.

After cloning the project, you can build and run it using *make*:

```
make clean run 
```

The executable created by this project is called *main*.

## Take Home

1. The resulting address from pointer arithmetic is the same as the resulting
address of an array element.  That is, ```str_array + 6 == &str_array[6]```.
2. For the pupose of standard template library "sequence containers" such as *vector*
and *list*, the type of an iterator of an array
is a pointer to an element of the array.  I.e., for an array of struct *foo*, 
the type of the iterator is pointer to *foo*.
