#!/bin/bash


file=$1

g++ $file -g 

./a.out

rm -rf a.out
