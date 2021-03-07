# PSS2-HW1

#### *Simpliﬁcations and assumptions:*

The input is the text (in the form of one line up to 5000 characters). It consists of several sentences (separated by dots). Your task is to:

• Write a program that reads the text from the ﬁle,

• Write a function that breaks the input text into sentences,

• Write a function that returns all sentences that contain the word from the input and make the word UPPERCASE in sentences.

#### *Requirements:*

• To read the data from the ﬁle in.txt. First comes the text line, then comes the line that indicates the number of words, and then in each line comes the query word.

• To write the result in the ﬁle out.txt ﬁle. For each word print the number of found sentences and these sentences with uppercased word.

• The text to the ’search’ function should be given as a set of sentences.

• Try to avoid unnecessary copy of sentences and write eﬀective code.

• There should be Readme.md ﬁle in the root folder with the project description, how to run the code, all dependencies installation and versions, maybe other instructions.

• Use C++

• If something was not mentioned - it means on your choice.

#### *Example of Input and Output:*

```
/* Sample input data: */
Lorem Ipsum is simply a dummy text of the printing and typesetting industry. 
Lorem Ipsum has been the industry’s standard dummy text ever since the 1500s, 
when an unknown printer took a galley of type and scrambled it to make a type specimen book. 
It has survived not only ﬁve centuries, but also the leap into electronic typesetting, 
remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset 
sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like 
Aldus PageMaker including versions of Lorem Ipsum.
2 
dummy 
release

/* Sample output data: */
2 
Lorem Ipsum is simply a DUMMY text of the printing and typesetting industry. 
Lorem Ipsum has been the industry’s standard DUMMY text ever since the 1500s, 
when an unknown printer took a galley of type and scrambled it to make a type specimen book.
1 
It was popularised in the 1960s with the RELEASE of Letraset sheets containing Lorem Ipsum passages, 
and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.
```

#### *Dependencies*

C++ 14
CMake 3.17

#### *How to run the code*

[1] Download source from GitHub

[2] Open terminal

[2] Type command to install gcc

[3] Go to that folder where you've download source

[4] Compile the program using the following command:

  -  gcc main.cpp

[5] To run the program type the following command

  - ./a.out
