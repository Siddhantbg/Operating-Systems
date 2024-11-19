echo "enter nos.:"
read n
f1=0
f2=1
echo "factorial is" 
echo $f1 
echo $f2
for(( i=2; i<n; i++))
do
	f3=$(( f1 + f2))
	echo $f3
	f1=f2
	f2=f3
done
