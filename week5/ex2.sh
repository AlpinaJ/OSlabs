while ln input.txt file.lock 2>/dev/null
do
	sleep 1
done

a=0
while [ $a -lt 10 ]
do
	num=$(tail -n 1 input.txt)
	echo $(($num + 1)) >> input.txt
	a=$((a+1))
done
rm -f file.lock