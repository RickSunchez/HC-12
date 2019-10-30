from tkinter import *
import json


def draw_coroners():
    f = open("coroners.json", "r")
    coroners = json.load(f)

    root = Tk()
    root.geometry("500x500")
    root.title("Sq_test")

    c = Canvas(root, width=500, height=500, background="white")
    c.pack()

    x = []
    y = []

    for pt in coroners:
        x.append(float(pt["x"]))
        y.append(float(pt["y"]))

    xMin = float(coroners[x.index(min(x))]["x"])
    yMin = float(coroners[x.index(min(x))]["y"])

    for i in range(0,len(x)):
        x[i] = 100 + (x[i] - xMin) * 100000
        y[i] = 100 + (y[i] - yMin) * 100000
        c.create_oval(x[i],
                      y[i],
                      x[i]+10,
                      y[i]+10)

    print(x, y)
    root.mainloop()
