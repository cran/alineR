\name{ALINE.segments}
\alias{ALINE.segments}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Similarity scores of aligned segments
}
\description{
Return vector of similarity scores for each optimally aligned segment.
}
\usage{
ALINE.segments(result, 
	Syllabic = 5, Place = 40, Stop = 50, 
	Voice = 10, Nasal = 10, Retroflex = 10,
	Lateral = 10, Aspirated = 5, Long = 1,
	High = 5, Back = 5, Round = 5, sk=10)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{result}{
  The value returned from raw.alignment() function, which is a list containing four elements.
}
  
 \item{Syllabic, Place, Stop, 
  Voice, Nasal, Retroflex,
	Lateral, Aspirated, Long,
	High, Back, Round}{
Feature weight used by the ALINE algorithm to determine the phonetic distance.
 }
 \item{sk}{
 Skip penalty in determining the alignment
 }
}

\details{
This function returns the similarity scores for each pair of aligned segments from the optimal alignment. The sum of these values is equal to the similarity score.
}
\value{
\item{vec}{
A numeric vector. The length of the vestor is equal to the number of aligned segments. The value of the ith element is the similarity score for that segment pair.
}
}

\author{
Guowei Sun
}

\examples{
  # align words
  result<-raw.alignment(c("watu","dat"))
  
  # print the alignment followed by the sim score 
  # for each pair of aligned segments
  cat(result[[3]],result[[4]],sep='\n') 
  ALINE.segments(result)

}

\keyword{ Similarity Score }
\keyword{ alignment }% __ONLY ONE__ keyword per line
