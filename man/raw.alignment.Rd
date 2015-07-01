\name{raw.alignment}
\alias{raw.alignment}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
R/C++ Interface
}
\description{
The R/C++ interface functions to ALINE. It is called by aline(), which is the preferred way to access it in most cases. The default features weights are those defined in Kondrak (2000). 
}
\usage{
raw.alignment(s, 
	Syllabic = 5, Place = 40, Stop = 50, 
	Voice = 10, Nasal = 10, Retroflex = 10,
	Lateral = 10, Aspirated = 5, Long = 1,
	High = 5, Back = 5, Round = 5, sk=10)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{s}{
A pair of ASCII-encoded words as defined by ALINE.map().
}
 \item{Syllabic, Place, Stop, 
  Voice, Nasal, Retroflex,
	Lateral, Aspirated, Long,
	High, Back, Round}{
Feature weights used to determine the optimal alignment.
 }
 \item{sk}{
 The skip penalty used to determine the optimal alignment.
 }
}
\value{
%%  ~Describe the value returned
%%  If it is a LIST, use
A list containing the following elements:
\item{'word pairs'}{The original word pair in ALINE ASCII encoding.}
\item{'similarity score'}{The similarity score returned by ALINE.}
\item{alignment1}{The alignment of the first word presented in ALINE symbols.}
\item{alignment2}{The alignment of the second word presented in ALINE symbols.}
}

\references{
Kondrak, G. (2000). A new algorithm for the alignment of phonetic sequences. In Proceedings of the 1st North American Chapter of the Association for Computational Linguistics Conference.
}

\examples{
s<-c("digNgNira","dinnira")
raw.alignment(s)

}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.

