import tkinter as tk

window=tk.Tk()
window.geometry('512x512')
window.title("Tabular transposition")
canvas = tk.Canvas(window, width = 512, height = 150)

def val():
    pass
   
def enc_page():
     from module import enc
   
def dec_page():
    from module import dec

photo = tk.PhotoImage(file = 'image/2.png')
canvas.pack()
frame_2=tk.Frame(height=15,width=200)
canvas.create_image(55, 55, image=photo)
canvas.create_text(300, 100, text = 'Tabular Transposition', font = ('Helvetica', 19, 'bold'), justify = 'center', fill='brown')
canvas.update
B1 = tk.Button( text ="CYPHER",command=enc_page);
B2 = tk.Button( text ="DECYPHER",command=dec_page);
canvas.pack()
B1.pack()
frame_2.pack()
B2.pack()

window.mainloop()