
from cgitb import text
import tkinter as tk
import math
  
# Top level window
window = tk.Tk()
window.title("CYPHER WINDOW")
window.geometry('512x512')
canvas = tk.Canvas(window, width = 512, height = 120)
canvas.pack()
canvas.create_text(250, 100, text = 'CYPHER', font = ('Helvetica', 19, 'bold'), justify = 'center', fill='brown')
inputtxt = tk.Text(window,
                   height = 5,
                   width = 50)

input_key = tk.Text(window,
                   height = 2,
                   width = 25)

def encrypt(message,key):
    column = len(key)
    row = math.ceil(len(message)/len(key))
    ordered_key = sorted(list(key))
    print(ordered_key)
    table=[]
    counter = 0
    ciphred_message=[]
    
    # puting the message characters to a table
    for i in range(row):
        table.append([])
        for j in range(column):
            if(counter<len(message)):
                table[i].append(message[counter])
                counter+=1

    #filling the remaining spaces of the last row with None
    blank_spaces= (row*column)-len(message)
    for i in range(blank_spaces):
        table[row-1].append("_")

    #finding the order of the keys for reading the columns in correct order
    order_of_keys=[]
    checked=[]
    for i in ordered_key:  
        for j in range(len(key)):
            if(key[j]==i and i not in checked):
                order_of_keys.append(j)
        checked.append(i)

    #reading the table in columns
    for order in order_of_keys:
        for culumn_element in range(row):
            ciphred_message.append(table[culumn_element][order])

    ciphred_message=''.join([str(character) for character in ciphred_message])
    return ciphred_message




  
# TextBox Creation
fr=tk.Frame(height=20,width=512)
canvas=tk.Canvas(window, width = 512, height = 150)

fr_2=tk.Frame(height=20,width=512)
lbl = tk.Label(window, text = "Put your message to be Cyphred here")
lbl_2 = tk.Label(window, text = "Put key here")
canvas.pack()
lbl.pack()
inputtxt.pack()
fr.pack()
lbl_2.pack()
input_key.pack()
fr_2.pack()
def encrypt_caller():
     pram1=str(inputtxt.get(1.0, "end-1c"))
     pram2=str(input_key.get(1.0, "end-1c"))
    
     val=encrypt(pram1,pram2)
     cyphred_text = open("cyphred.txt",'w')
     cyphred_text.write(val)
     cyphred_text.close()
     if len(val)!=0:
        forget()  
        new_window(val)
     
def new_window(val):
     global f_2, f_3,f_4,lbl_2,welcome, btn
     
     f_2=tk.Frame(window,height=20,width=512)
     f_3=tk.Frame(window,height=5,width=512)
     f_4=tk.Frame(window,height=100,width=512)
     
     lbl_2 = tk.Label(f_2,text = "The cyphred message is:",font=20)
     
     welcome = tk.Label(window,text=val,foreground="black",width=512,wraplength=500) 
     def fun():
          recreate()
     btn=tk.Button(window,text='back',command=fun)
     
     f_2.pack()
     
     lbl_2.pack()
     f_3.pack()
     welcome.pack()
     f_4.pack()
     btn.pack()
# Button Creation
def recreate( ):
     f_2.pack_forget()
    
     lbl_2.pack_forget()
     f_3.pack_forget()
     welcome.pack_forget()
     f_4.pack_forget()
     btn.pack_forget()
    
     canvas.pack()
     lbl.pack()
     
     inputtxt.pack()
     lbl_2.pack()
     fr.pack()
     input_key.pack()
     fr_2.pack()
     submit_Button.pack()
          
def forget():
     inputtxt.pack_forget()
     fr.pack_forget()
     lbl_2.pack_forget()
     canvas.pack_forget()
     lbl.pack_forget()

     input_key.pack_forget()
     fr_2.pack_forget()
     submit_Button.pack_forget()
submit_Button = tk.Button(window,
                        text = "submit", 
                        command = encrypt_caller)
submit_Button.pack()

window.mainloop()