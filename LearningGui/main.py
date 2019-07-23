import tkinter
class SampleApp():
    def __init__(self, *args, **kwargs):

        root = Tk.__
        init__(self, *args, **kwargs)
        self.label = Label(text="Choose the info to exclude (if any) on the \n left."
                                "Write the number of the  tags that should \n be associated with the information on the right.")
        self.label.pack()

        self.frame = VerticalScrolledFrame(root)
        self.frame.pack()


        buttons = []
        resource=[]
        label=[]
        for i in range(10):
            frame = Frame(self.frame.interior)
            frame.pack(side=TOP)

            buttons.append(Checkbutton(frame, text=str(i)+". "+ "Button" ))
            resource.append(Entry(frame, width=3))
            label.append(Label(frame,text="Name: Ryan"))

            buttons[-1].pack(side=LEFT)
            label[-1].pack(side=LEFT)
            resource[-1].pack(side=LEFT)