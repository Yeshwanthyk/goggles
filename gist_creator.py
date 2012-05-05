import math
import sys

class GistCreator():
  def __init__(self, file_pattern):
    filenames = file_pattern.split(',')
    self.sentences = []
    for filename in filenames:
      article_str = open(filename).read().lower()
      sentences_tmp = article_str.split('.')
      self.sentences.extend(sentences_tmp)

  def print_gist(self, tags):
    prob_sentences = []
    for sentence in self.sentences:
      words = sentence.split(' ')
      prob = 0
      for tag in tags:
        if tag in words:
          prob += 1
      prob_sentences.append((sentence, prob))

    sorted_sentences = sorted(prob_sentences, key=lambda x: x[1], reverse=True)
    print '==================================================='
    for i in range(0,15):
      print sorted_sentences[i][0]
    print '==================================================='
      
gist_creator = GistCreator(sys.argv[1])
tagfile = open('finaltags.txt','r')
for line in tagfile:
	line = line.strip()
	tags = line.split(',')	
	print tags
	gist_creator.print_gist(tags)
tagfile.close() 
  	
