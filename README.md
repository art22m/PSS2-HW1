# PSS2-HW1

This program accepts as input: text, the number of words to search and words to search in following form:
```
*text*
3 // Number of words to search
*wordToSearch1*
*wordToSeatch2*
*wordToSeatch3*
```
Program will find words to search into input text. After that program will output the number of sentences and then senteces, 
where needed words would be in uppercase.


*Example:*

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
