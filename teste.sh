#!/bin/bash
while true; do 
    var=($(seq -100000 10000 | shuf -n 100 | tr '\n' ' ')); 
    clear; 
    valgrind ./push_swap "${var[@]}" | ./checker_linux "${var[@]}" ; 
    ./push_swap "${var[@]}" | wc -l;  
    sleep 1; 
done
