#!/bin/bash
#sum.sh

sum=0
i=0
while [ $i -le 10 ]
do
	let "sum += i"
	let "i += 1"
done
echo "The sum is $sum."

