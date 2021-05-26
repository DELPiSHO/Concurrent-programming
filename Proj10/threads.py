import threading
import time
# Yauheni Dzianisau


# Matrix to calculate
# 94
n = [[3, 2, 1, 2], [4, 3, 2, 1], [1, 2, 2, 5], [1, 6, 0, 1]]
# 0
# n = [[1, 1, 1, 1], [1, 1, 1, 1], [1, 2, 2, 5], [0, 0, 0, 0]]
# 64
# n = [[0, 1, 2, 7], [1, 2, 3, 4], [5, 6, 7, 8], [-1, 1, -1, 1]]

# Here will be stored threads results
sumThreads = [0 for i in range(4)]


# Calculate 3x3 matrix
def sarrus(A):
    return (A[0][0] * A[1][1] * A[2][2] + A[0][1] * A[1][2] * A[2][0] + A[0][2] * A[1][0] * A[2][1]) - \
           (A[0][2] * A[1][1] * A[2][0] + A[0][0] * A[1][2] * A[2][1] + A[0][1] * A[1][0] * A[2][2])


# Submatrix 1
def matixOne(A):
    B = [[A[1][1], A[1][2], A[1][3]],
         [A[2][1], A[2][2], A[2][3]],
         [A[3][1], A[3][2], A[3][3]]]
    return B


# Submatrix 2
def matixTwo(A):
    B = [[A[1][0], A[1][2], A[1][3]],
         [A[2][0], A[2][2], A[2][3]],
         [A[3][0], A[3][2], A[3][3]]]
    return B


def matixThree(A):
    B = [[A[1][0], A[1][1], A[1][3]],
         [A[2][0], A[2][1], A[2][3]],
         [A[3][0], A[3][1], A[3][3]]]
    return B

def matixFour(A):
    B = [[A[1][0], A[1][1], A[1][2]],
         [A[2][0], A[2][1], A[2][2]],
         [A[3][0], A[3][1], A[3][2]]]
    return B


def thread1Task(A):
    global sumThreads
    B = matixOne(A)
    minor = sarrus(B)
    multiplier= A[0][0]
    sumThreads[0] = minor * multiplier

def thread2Task(A):
    global sumThreads
    B = matixTwo(A)
    minor = sarrus(B)
    multiplier= A[0][1]
    sumThreads[1] = minor * multiplier


def thread3Task(A):
    global sumThreads
    B = matixThree(A)
    minor = sarrus(B)
    multiplier= A[0][2]
    sumThreads[2] = minor * multiplier


def thread4Task(A):
    global sumThreads
    B = matixFour(A)
    minor = sarrus(B)
    multiplier= A[0][3]
    sumThreads[3] = minor * multiplier



def sumTasksthread():
    return sumThreads[0] - sumThreads[1] + sumThreads[2] - sumThreads[3]


print("With threads")
start = time.time()

t1 = threading.Thread(target=thread1Task(n))
t2 = threading.Thread(target=thread2Task(n))
t3 = threading.Thread(target=thread3Task(n))
t4 = threading.Thread(target=thread4Task(n))
t1.start()
t2.start()
t3.start()
t4.start()

threadAnswer = sumTasksthread()
end = time.time()
a = end - start
print("Total time:", "%.16f" % a)
print("Answer: ", threadAnswer)

print("Without")
start = time.time()
thread1Task(n)
thread2Task(n)
thread3Task(n)
thread4Task(n)
answer = sumTasksthread()
end = time.time()
a = end - start
print("Total time:", "%.16f" % a)
print("Answer: ", answer)

# print("Matrix 1", matixOne(n))
# print("Matrix 2", matixTwo(n))
# print("Matrix 3", matixThree(n))
# print("Matrix 4", matixFour(n))
