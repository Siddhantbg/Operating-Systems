echo "Enter Armstrong"
read n
m=$n
s=0
sum=0
while [ $n -gt 0 ]
do
	s=$((s+1))
	n=$((n / 10))
done

n=$m

while [ $n -gt 0 ] 
do
	r=$((n % 10))
	sum=$((sum + r ** s))
	n=$((n / 10))
done

if [ $m -eq $sum ]
then
	echo "armstrong"
else
	echo "not armstrong"
fi
		
