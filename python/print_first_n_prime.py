n = int(input("Enter the limit: "))
start = 2
count = 0
while count<n:
	flag = 0
	for i in range(2,start):
		if start % i ==0:
			flag =1
			break
	if flag==0:
		print(start)
		count+=1
	start+=1
