echo "enter no."
read n
f=1
for(( i=1; i<=n; i++))
do
	f=$((f * i))
done
echo "fact of" $n "is" $f
