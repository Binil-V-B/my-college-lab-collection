str = input("Enter the string: ")
count_of_a=0
count_of_e=0
count_of_i=0
count_of_o=0
count_of_u=0

for i in str:
	if i == 'a':
		count_of_a +=1
	if i == 'e':
		count_of_e +=1
	if i == 'i':
		count_of_i +=1
	if i == 'o':
		count_of_o +=1
	if i == 'u':
		count_of_u +=1

print("count of vowels")
print("a - ",count_of_a)
print("e - ",count_of_e)
print("i - ",count_of_i)
print("o - ",count_of_o)
print("u - ",count_of_u)
