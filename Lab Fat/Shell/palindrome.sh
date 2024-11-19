echo "enter no."
read n

rev_n=$(echo $n | rev)

if [ "$n" == "$rev_n" ]
then 
	echo "palidrome"
else
	echo "not palindome"
fi
