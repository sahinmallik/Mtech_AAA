import numpy as np

def add_matrix(A, B):
    
    return np.add(A, B)

def subtract_matrix(A, B):
    
    return np.subtract(A, B)

def strassen(A, B):
    
    n = len(A)

    
    if n == 1:
        return A * B

    
    k = n // 2

    A11, A12, A21, A22 = A[:k, :k], A[:k, k:], A[k:, :k], A[k:, k:]
    B11, B12, B21, B22 = B[:k, :k], B[:k, k:], B[k:, :k], B[k:, k:]

    
    P1 = strassen(A11, subtract_matrix(B12, B22))
    P2 = strassen(add_matrix(A11, A12), B22)
    P3 = strassen(add_matrix(A21, A22), B11)
    P4 = strassen(A22, subtract_matrix(B21, B11))
    P5 = strassen(add_matrix(A11, A22), add_matrix(B11, B22))
    P6 = strassen(subtract_matrix(A12, A22), add_matrix(B21, B22))
    P7 = strassen(subtract_matrix(A11, A21), add_matrix(B11, B12))

    # Combine the results into the resulting matrix C
    C11 = P5 + P4 - P2 + P6
    C12 = P1 + P2
    C21 = P3 + P4
    C22 = P5 + P1 - P3 - P7

    
    C = np.vstack((
        np.hstack((C11, C12)),
        np.hstack((C21, C22))
    ))

    return C

def next_power_of_2(n):
    
    return 1 if n == 0 else 2 ** (n - 1).bit_length()

def pad_matrix(A, size):
    
    padded = np.zeros((size, size))
    padded[:A.shape[0], :A.shape[1]] = A
    return padded

if __name__ == "__main__":

    A = np.array([ [1, 1, 1, 1], 
            [2, 2, 2, 2], 
            [3, 3, 3, 3], 
            [2, 2, 2, 2] ])
    B = np.array([ [1, 1, 1, 1], 
            [2, 2, 2, 2], 
            [3, 3, 3, 3], 
            [2, 2, 2, 2] ])

    
    n = next_power_of_2(max(A.shape + B.shape))

    
    A_padded = pad_matrix(A, n)
    B_padded = pad_matrix(B, n)
    
    C_padded = strassen(A_padded, B_padded)

    C = C_padded[:A.shape[0], :B.shape[1]]

    print("Result of Strassen's Matrix Multiplication:")
    print(C)
