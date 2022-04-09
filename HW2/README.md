Linked list implementation to search IPv4 addresses:

Program structure and design:
For this assignment, you will create your own test data file using the sample format. Grading will involve using different data files with the same format.
Create a structure type called address_t with components for the four integers of an IPv4 address along with a fifth component in which to store an associated alias (key field) of up to 10 characters. You will then create a singly linked list of address_t structures which will contain all of the address/alias pairs read in from the “CS531_Inet.txt” file. For this exercise, the linked list may be unsorted.

Once the linked list has been created, the user will receive the following menu options:

1) Addaddress: Prompt user for an IPv4 address/alias pair. Both data elements are read in from the keyboard as character strings. The address string will be parsed and the four component integers will be stored separately (hint: use sscanf()). If either the address or alias already exists within the list, display an error message and redisplay the menu.
2) Lookupaddress: Prompt user for an alias, and display the corresponding address. If the alias does not exist within the list, display an error message and redisplay the menu.
3) Updateaddress: Prompt user for an alias and display the corresponding address. Allow user to update the address and have the newly entered address replace the old address within the linked list assuming the new address does not already exist within the list. If the alias does not exist within the list, or the newly entered address is a duplicate, display an error message and redisplay the menu.
4) Deleteaddress: Prompt user for an alias, and display the corresponding address. Confirm that user wishes to delete this node from the linked list. If the alias does not exist within the list, display an error message and redisplay the menu.
5) Displaylist: Display all address/alias pairs within the list. For this exercise, the list is unsorted. If the list is empty, print a message to that effect and redisplay the menu. Also display the number of nodes within the list.
6) Displayaliasesforlocation: Prompt user for an address location. (i.e. two separately entered values between 0 – 255). If either value is out of range, re- prompt. List all aliases that map to this location. If the location does not exist within the list, display an error message. 
7) Savetofile: Prompt user for a file name, and save the revised list to the specified file keeping file format consistent with that of the input file (i.e. one address/alias pair per line.)
8) Quit: Exit program.
