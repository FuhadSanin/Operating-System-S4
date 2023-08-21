echo -n "Enter the numbers : "
read nums


largest=0

for num in $nums
do
    if [ $largest -lt $num ]
    then
        largest=$num
    fi
done
echo -n "Largest : $largest"