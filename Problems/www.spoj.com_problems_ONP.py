def calculate_post_fix(expression):
    stack = []
    for chars in expression:
        if chars == ')' and len(stack) > 0:
            operator_stack = []
            operand_stack = []
            while stack[-1] != '(':
                if stack[-1] in ['*','^','/','%','+','-']:
                    operator_stack.insert(0, stack.pop())
                else:
                    operand_stack.insert(0, stack.pop())
            if stack[-1] == '(':
                stack.pop()
            str1 = ""
            str2 = ""

            stack.append(((str2.join(operand_stack)).replace(' ',''))+
                        (str1.join(operator_stack)).replace(' ',''))
        else:
            stack.append(chars)
    print(str(stack[0]))


T = int(input())

while (T > 0):
    expression = input()
    calculate_post_fix(expression)
    T -= 1



