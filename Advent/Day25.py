CARD_PUBLIC = 14788856
DOOR_PUBLIC = 19316454
CARD_LOOP = -1
DOOR_LOOP = -1
i = 1
key = 1
while True:
    key = key*7%20201227
    if key == CARD_PUBLIC:
        CARD_LOOP = i
    if key == DOOR_PUBLIC:
        DOOR_LOOP = i
    if CARD_LOOP != -1 and DOOR_LOOP != -1:
        break
    i+=1
print(CARD_LOOP, DOOR_LOOP)
print(DOOR_PUBLIC ** CARD_LOOP % 20201227)