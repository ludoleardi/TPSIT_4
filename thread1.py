from time import sleep
from threading import Thread

class Task1(Thread):
    def __init__(self, temp):
        Thread._init_(self)
        self.temp = temp
    
    def run(self):
        print(f"Start tread")
        sleep(self.temp)
        print(f"finish tread")

class Task2(Thread):
    def _init_(self):
        Thread._init_(self)
    
    def run(self):
        print(f"Start tread contatore")
        for i in range (0,20):
            sleep(1)
            print(i)
        print(f"finish tread contatore")

def main():
    t1 = Task1(10)
    t2 = Task2()
    t1.start()
    t2.start()

if __name__ == "__main__":
    main()