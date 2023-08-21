echo -n "Enter two number : "

read a
read b

temp=$a
a=$b
b=$temp

echo -n "Swapped no. a=$a b=$b"