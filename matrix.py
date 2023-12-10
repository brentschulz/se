
def add_matrices(mat1, mat2):
    return [[a + b for a, b in zip(row1, row2)] for row1, row2 in zip(mat1, mat2)]

def subtract_matrices(mat1, mat2):
    return [[a - b for a, b in zip(row1, row2)] for row1, row2 in zip(mat1, mat2)]

def multiply_matrices(mat1, mat2):
    return [[sum(a * b for a, b in zip(row1, col2)) for col2 in zip(*mat2)] for row1 in mat1]

def transpose_matrix(mat):
    return [[row[i] for row in mat] for i in range(len(mat))]

matrix1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
matrix2 = [[9, 8, 7], [6, 5, 4], [3, 2, 1]]

result_addition = add_matrices(matrix1, matrix2)
print("Matrix Addition:")
for row in result_addition:
    print(row)

result_subtraction = subtract_matrices(matrix1, matrix2)
print("\nMatrix Subtraction:")
for row in result_subtraction:
    print(row)

result_multiplication = multiply_matrices(matrix1, matrix2)
print("\nMatrix Multiplication:")
for row in result_multiplication:
    print(row)

result_transpose = transpose_matrix(matrix1)
print("\nMatrix Transpose:")
for row in result_transpose:
    print(row)

