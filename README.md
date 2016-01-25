# C project and Python wrapper skeleton

## Purpose

This project aims to provide a skeleton template of

1. A C library project which conforms to some methodology in writing the code.
2. A Python interface of the C library

## The C project

The C project template conforms to [scalable C](https://hintjens.gitbooks.io/scalable-c/) standard and [CLASS C language style](http://rfc.zeromq.org/spec:21).

- Project name: Scalable C Template
- Project prefix: sct

ref:
- [Scalable C](https://hintjens.gitbooks.io/scalable-c/) by @hintjens
- [scalable-c/globdom](https://github.com/scalable-c/globdom)
- [zproject](https://github.com/zeromq/zproject)

## The Python wrapper

Use [Cython](http://cython.org/) to make a Python wrapper of the C public APIs.

