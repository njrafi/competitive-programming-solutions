if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    res = int(0)
    for i in student_marks[query_name]:
        res = res + i
    res /= 3
    
    print("%.2f" %res)