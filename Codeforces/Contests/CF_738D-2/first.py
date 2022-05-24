def invert(d):
	l = {v: k for k,v in d.items()}
	return l

d = { 1 : "one", 2 : "two", 3 : "one" }

a = input("Enter your value: ")
print(a)
l = invert(d)
print(l)