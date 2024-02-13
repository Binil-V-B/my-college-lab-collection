print("calculator\n1-addition\n2-subtraction\n3-multiplication\n4-division\n5-exit")
while True:
	n = int(input("Enter your choice: "))
	a = int(input("Enter the first operand: "))
	b = int(input("Enter the second operand: "))
	if n==1:
		print(a,"+",b,"=",(a+b))
	elif n==5:
		break

