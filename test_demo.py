import random

def generate_random_char():
    # set the possible random characters
    list_of_possible_characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
    # get a random index and retrieve the random character
    random_index = random.randint(0,len(list_of_possible_characters) - 1)
    random_char = list_of_possible_characters[random_index]
    return random_char

# main program loop
main_loop_status = "running"
while main_loop_status == "running":
    # get the user input -> yes/no on generating password
    user_input_generate_password = input("do you want to generate a random password? yes/no: ")
    # check if the user input is yes/no
    if (user_input_generate_password == "yes"):
        # generate the password
        print ("a password will now be generated")
        user_input_password_length = input("how many characters must be the password be? Enter a number:")
        # convert the password length user input into a string
        password_length_converted = 0
        try:
            # attempt to convert the password length user input into an int
            password_length_converted = int(user_input_password_length)
            # if the password length is a valid int
            if (password_length_converted <= 0):
                # if the password length is 0
                print ("the password length must be greater than 0")
            if (password_length_converted > 0):
                # if the password length is greater than 0
                print ("a password of ",password_length_converted," length will now be generated", sep='')
                # generate the password
                password_string = ""
                for x in range(1,password_length_converted + 1):
                    # generate the random character
                    random_char = generate_random_char()
                    password_string = password_string + random_char
                print ("your password is: ",password_string,sep='')
        except:
            print ("invalid number. please enter a number without a decimal")
    if (user_input_generate_password == "no"):
        # exit the program
        print ("the program will exit")
        main_loop_status = "not running"
    if (user_input_generate_password != "yes") and (user_input_generate_password != "no"):
        # if the user input is not yes AND not no
        print ("invalid input, please enter yes or no")

