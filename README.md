 ------------------------------------------------------------ 


Hi there! Welcome to Markov Sentence Generator!
Here I will tell some algorithm that we use in the project.

First, create a .txt document to save the origin content of sentence. 

Second, define and use cin to input two prefix, this is the Markov Sentence prefix.

Third, use two prefixs to search the content in the .txt, then if find out the word marked with these two prefixs(follow to these two words),
this word will define as postfix. If marked with several words, use the random one as postfix.

Fourth, the sentence move, save the prefix 2 to the position of prefix 1, abandon the previous prefix 1, then save the postfix to the position of prefix 2.

Fifth, the sentence move away, until encounter a dot. The whole sentence has created.

 ------------------------------------------------------------ 

How to use it:

firstly, write "g++ main.cpp" in the bash field;

secondly, write "./a.out" in the bash field;

after that , it will print "please input prefix 1:" you can input a word then Enter(eg: shall)

then, it will print"please input prefix 2:" to ask you input another word(eg: be) and Enter;

Finally, you can get the sentence witch begin with these two words from out prepared document.



## Support & Documentation
