import random

def generate_random_char ():
    random_char_list = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890=+-_[];,."
    random_index = random.randint(0,len(random_char_list) - 1)
    random_char = random_char_list[random_index]
    return random_char


program_loop_status = "running"

while program_loop_status == "running":
    print ("do you want to generate a password? yes/no")
    user_input = input("yes/no\n")
    if (user_input == "yes"):
        print ("how long should be password be? Enter a number")
        # get user input for password length
        user_input_password_length = input()
        # convert string input to int
        user_input_converted = 0
        try:
            # check if the user input is a valid int
            user_input_converted = int(user_input_password_length)
            print ("a password of ", user_input_converted, " characters will be generated", sep='')
            # if the user input is a valid int, generate the password
            password_string = ""
            for x in range (1,user_input_converted + 1):
                # generate a random character
                random_char = generate_random_char()
                password_string = password_string + random_char
            print ("your password is:\n", password_string, sep='')
        except:
            print ("please enter a valid integer")
        # if it is a valid int, generate the password
    if (user_input == "no"):
        print ("the program will exit")
        program_loop_status = " not running"
    if (user_input != "yes" and user_input != "no"):
        print ("please enter yes or no")
