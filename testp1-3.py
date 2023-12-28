print("**letter grade**")

s = input("Enter score (0-100): ")
score = int(s)

x = 99

if score >= 90:
  letter = "A"
  print(score, "case 1")
  x = 2
elif score >= 80:
  print("case 2")
  letter = "B"
  x = 98
  print("good job!", score)
elif score >= 70:
  letter = "C"
elif score >= 60:
  letter = "D"
  print("okay")
  print("score in 60..70 range")
  x = 41
  print("almost done!")
else:
  x = 12345
  letter = "F"
  print("last case")

print("Your letter grade is", letter, x)

print("**done letter grade**")