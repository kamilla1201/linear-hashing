import csv
import random
import string

id_size = 8
name_size = 200
bio_size = 500

def gen_id():
    id_begin = 10 ** (id_size-1)
    id_end= 10 ** (id_size) - 1
    # print(id_begin, id_end)
    _id = random.randint(id_begin, id_end)
    # print(_id)
    return _id

def main():
    rand_str = lambda n: ''.join([random.choice(string.ascii_lowercase) for i in range(n)])

    with open('Employee.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',')
        for i in range(8000):
            uid = gen_id()
            mid = gen_id()
            name_len = random.randint(1, name_size)
            bio_len = random.randint(1, bio_size)
            name = rand_str(name_len)
            bio = rand_str(bio_len)
            writer.writerow([uid, name,bio, mid])

if __name__ == "__main__":
    main()
