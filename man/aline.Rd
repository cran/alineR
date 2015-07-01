\name{aline}
\alias{aline}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Calculate aline distances
}
\description{
The main user function for returning Aline Distances. Also it provides options for additional outputs such as the raw alignments and individual distance measurements. Word lists are passed as two vectors (w1, w2) such that the nth element of each vector are compared.
}
\usage{
aline(w1, w2, sim = FALSE, m1 = NULL, m2 = NULL, mark=FALSE, alignment = FALSE, ...)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{w1}{
A vector of IPA-encoded words.
}
  \item{w2}{
A second vector of IPA-encoded words to be aligned with w1.
}
  \item{sim}{
By default calculates the aline distance (normalized between word pairs) as defined in Downey et al. 2008. If TRUE aline similarity scores from (Kondrak 2000) are returned.
}
\item{m1}{
User defined IPA symbol. See map() for details.
}
  \item{m2}{
User defined ALINE symbol. See map() for details.
}
\item{alignment}{
If TRUE the funciton will return the aligned IPA word pairs.}
\item{mark}{
If TRUE the result will mark the invalid characters with "@"
}
\item{...}{
Other parameters passed to raw.alignment().}
}

\value{

If alignment=FALSE the function returns a vector of scores such that the nth score is the aline distance between the nth elements of x and y.

If alignment=TRUE the function returns a data frame with each word pair represented in a column and with the following rows:

\item{w1}{The original IPA-encoded word vector.}
\item{w2}{The original IPA-encoded word vector.}
\item{scores}{The similarity or distance score as defined by argument sim.}
\item{a1}{The alignment of the first word.}
\item{a2}{The alignment of the second word.}



}
\references{
Kondrak, G. (2000). A new algorithm for the alignment of phonetic sequences. In Proceedings of the 1st North American Chapter of the Association for Computational Linguistics Conference.

Downey, S. S., Hallmark, B., Cox, M. P., Norquest, P., & Lansing, J. S. (2008). Computational feature-sensitive reconstruction of language relationships: Developing the ALINE distance for comparative historical linguistic reconstruction. Journal of Quantitative Linguistics, 15(4), 340-369.
}
%\encoding{ISO-8859-13}
\author{
Sean Downey and Guowei Sun
}
\note{
This function will issue warnings and drop unknown characters if an input word contains unmapped IPA symbols. If this happens, the warning can be eliminated by appending an additional IPA-ASCII character mapping %(see ALINE.map()).
}
\seealso{
\code{\link{raw.alignment},\link{map}}
}

\examples{
x<-c(intToUtf8(c(361,109,108,97,116,952)),intToUtf8(c(100,105,331,331,105,114,97)))
y<-c(intToUtf8(c(418,109,108,97,116,952)),intToUtf8(c(100,105,110,110,105,114,97)))
# For CRAN requirement, to see x and y, type x,y in R console
x
y
aline(w1=x,w2=y)

# user substitution
aline(w1=x,w2=y,m1=intToUtf8(418),m2="o")
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
