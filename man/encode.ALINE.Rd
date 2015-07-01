\name{encode.ALINE}
\alias{encode.ALINE}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Encode IPA as ALINE ASCII notation
}
\description{
Translates a vector of IPA words into the ASCII encoding scheme used by aline via ALINE.map. Uses UTF-8 encodings. 
}
\usage{
encode.ALINE(x, mark = FALSE, m1 = NULL, m2 = NULL)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{x}{
A vector of IPA words to encode.
}
  \item{mark}{
If FALSE unknown symbols are omitted; if TRUE invalid symbols are replaced with "@".
}
  \item{m1}{
A vector of IPA characters to encode. See map() for detail.
}
\item{m2}{
A vector of ALINE encodings. see map() for detail
}
}
\examples{
y<-c(intToUtf8(c(418,109,108,97,116,952)),intToUtf8(c(100,105,110,110,105,114,97)))
y
encode.ALINE(y,m1=intToUtf8(418), m2="o")
}
\author{
Sean Downey and Guowei Sun
}


\section{ Warning }{
This function will return a warning if it encounters an IPA symbol not included in the ALINE map or defined by the user. It will then ignore that symbol and decode the rest. Use mark=TRUE to see what is being omitted and map(m1, m2) to provide a new mapping.
}

\seealso{
\code{\link{decode.ALINE}}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
