#
# Simple python program, focusing on part 01 of project
#
# NOTE: an online Python system is avaliable @ https://www.onlinegdb.com/
#
print("**starting**")

i = 1
j = 10
k = 100

one = i + 1
two = k - 1
three = j ** 3

print("one=", one)
print("two=", two)
print("j cubed is", three, ".")

i = 1 + i
i = 2 * i
j = k / 3
k = k % 3

print("**values of i, j, k, s3**")
print(i)
print(j)
print(k)

s1 = "cs"
s2 = "141"
s3 = s1 + s2  # string concatenation
print(s3)

print("**values of conditions c1, c2, c3**")
c1 = one > 0   # true
c2 = one < 2   # false
c3 = two == 99 # true

print(c1)
print(c2)
print(c3)

print("**done**")
