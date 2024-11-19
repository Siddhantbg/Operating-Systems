echo "Enter no."
read n

if [ $n -eq 0 ] || [ $n -eq 1 ]
then
	echo "no. is not a prime"
fi

for (( i=2; i<$((n/2)); i++ )) 
do 
	if [ $((n % i)) -eq 0 ]
	then
		echo "no. is not a prime"
exit 0
	fi 
done
echo "is a prime number"
