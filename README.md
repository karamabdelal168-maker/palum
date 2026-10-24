# Palum

Hi, Palum is a transpiler that turns txt files of dialogue into an executable gdscript file that runs the previously mentioned dialogue. I made this to solve 2 problems I had, first of all, me and my team wanted to make games but we quickly realised that it would take us a lot of time to make every system everytime we started a new game would take a lot of time, so we decided to make some systems/tools that would make it faster and easier to make our games and one of the things we needed to take care of is dialogue in our games. Second of all, I have been learning c++ and I wanted to start making projects with c++ to gain experience with the langauge and I decided to hit 2 birds with one stone, with the stone being Palum.

# For who is palum for

This isn’t for most people and definitely not for window users since I couldn’t get it to work on winodows yet but I will try to make a windows build soon. I mainly have in mind people in teams and people who don’t want to deal with JSON files.

# How to install palum

Just git clone this repo and run compile.sh

# How to use palum

First you make a .txt and write the dialogue in it

## Making a speaker

A speaker is the person who speaks the line of dialogue

to make one you have to use ; to make new speaker and make him say a line like this

```
mark;
```

after making the speaker for the first time you will use a : to make him say another line

```
mark;

mark:
```
| - | - |
| ; | Used to make a new speaker and make the speaker say a line |
| : | Used to make an already existing speaker say a line |


And the transpiler ignores spaces after the last character of the speakers name, so these two are the same

```
mark                    ;

mark;
```

## Making a new line

To make a line you have to write it after the ; or : and end it with a \\

```
mark;hi I am mark\

mark:I am happy to meet you
```

the transpiler also ignores new lines and tabs

## Using the escape character

The escape character in Palum is @ and these are how you can use it

| @@ | Prints the character @ |
| - | - |
| @; | Prints the character ; |
| @: | Prints the character ; |
| @\\ | Prints the character \\ |
| @n | Adds a new line |
| @t | Adds a tab |


## Using palum in godot

To use it first you have to go the terminal and type palum in it. It will ask for a file path, put the absolute file path of the txt file

then in godot when you want to start the dialogue you will need to run name\_of\_txt\_file.init() if you have images for the speaker and there will be a parameter for each speaker that needs an image(you can skip this if you don’t have images for the speakers

```
dialogue.init(load(“path to image”))

#this example is for a mark example in Making a new line
```

then you need to call name\_of\_txt\_file.play\_dialogue() and it has 6 parameters and the first 2 are mandatory.

| 1st  parameter(tree) | The tree of the ui elements, usually it get\_tree() or line\_label.get\_tree()  |
| - | - |
| 2nd  parameter(line\_label) | The rich text label that will display the lines |
| 3rd  parameter(speaker\_label) | The rich text label that will display the speaker’s name and by default it is set to null |
| 4th  parameter(speaker\_image) | The texture rect that will display the speaker’s image and by default it is set to null |
| 5th  parameter(input\_func) | The input action that will move on the next line and by default it is set to “ui\_accept” |
| 6th  parameter(speed) | The speed of how fast the characters gradually appear and by defualt it is set to 1.0 |


For example

```
dialogue.init(load(“path to image”))

dialogue.play_dialogue(get_tree(),line_label,null

speaker_image,”ui_accept”,1.5)
```

and a final note is that palum automatically show()s and hide()s the ui elements for you.

That’s all for this README. Have fun making dialogue. 
