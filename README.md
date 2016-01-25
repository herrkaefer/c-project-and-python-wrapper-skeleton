# C Project and Python Wrapper Skeleton

## The Goal

This project aims to provide a skeleton template of

1. A C library which conforms to some methodology in project organization and code style.
2. A Python interface of the C library

It then can be used as a template or standard reference for further development.

## The C Project

The C project template conforms to [Scalable C](https://hintjens.gitbooks.io/scalable-c/) methodology and [CLASS C language style](http://rfc.zeromq.org/spec:21).

- Project name: Scalable C Template
- Project prefix: sct

ref:
- [Scalable C](https://hintjens.gitbooks.io/scalable-c/) by @hintjens
- [scalable-c/globdom](https://github.com/scalable-c/globdom)
- [zproject](https://github.com/zeromq/zproject)

## The Python Wrapper

Use [Cython](http://cython.org/) to make a Python wrapper of the C public APIs.

