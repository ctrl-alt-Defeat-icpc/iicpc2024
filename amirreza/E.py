n = int(input())
text = list(input())
arr = list(map(int, input().split()))

j = 0
for i in range(len(text)):
    if text[i] == 'X':
        text[i] = int(arr[j])
        j += 1

for i in range(len(text)-1, -1, -1):
    if text[i] == 'A':
        text[i] = text[i+1]+text[i+2]
        text.pop(i+1)
        text.pop(i+1)

    elif text[i] == 'B':
        text[i] = max(text[i + 1], text[i + 2])
        text.pop(i+1)
        text.pop(i+1)

print(text[0])
