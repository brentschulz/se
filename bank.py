
class Bank:
    def __init__(self):
        self.balance = 0
        print("Account created!")
    

    def deposit(self):
        n = int(input("Enter amount to deposit: "))
        self.balance = self.balance + n
        print("Amount deposited. New balance is: ", self.balance)


    def withdraw(self):
        m = int(input("ENter amount to withdraw: "))
        if self.balance > m:
            self.balance = self.balance - m
            print("Amount withdrawn. New balance is: ", self.balance)
        else:
            print("Amount cant be withdrawn") 

account = Bank()
account.deposit()
account.withdraw()




