import random
import string


ROUND = 10
ALLOWED_CHARS = string.ascii_letters
for _ in range(ROUND):
    str_size = random.randint(10, 1000)
    output = ''.join(random.choice(ALLOWED_CHARS) for _ in range(str_size))
    print(output)
    
