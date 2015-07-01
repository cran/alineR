\name{decode.ALINE}
\alias{decode.ALINE}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{Decode ALINE ASCII output}
\description{
Decode aligned ALINE ASCII output into the original IPA characters while indicating the optimal alignment with vertical bars ('|').
}
\usage{
decode.ALINE(x, y, m1 = NULL, m2 = NULL)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{x}{
A vector containing the original IPA word. 
}
\item{y}{
A vector containing the aligned characters in ALINE notation.
}
\item{m1}{
A vector of IPA characters to encode. See map() for details.
}
\item{m2}{
A vector of ASCII ALINE encodings. See map() for detail.
}
}

\value{
\item{word}{
The alignment of the word in the IPA notation.
}
}

\author{
Sean Downey and Guowei Sun
}

\examples{
x<-intToUtf8(c(611,117,108,108,97))
y<-"|         gS       u       l       l       a       |  "
decode.ALINE(x,y)

# user-specified mapping. Should be consistent with encode.ALINE() function
x<-intToUtf8(c(418,109,108,97,116,952))
y<-"|  o   m   l   a   t   tS  |  "
decode.ALINE(x,y,m1=intToUtf8(418), m2="o")
}

\note{
The opriginal IPA word is required because of many-to-one relationships when mapping ALINE-->IPA. For example, both intToUtf8(249) and  intToUtf8(250) are mapped to ASCII 'u' (see map()) so the process cannot be reversed without the original IPA word. User-specified mappings should be consistent with encode.ALINE().
}
\section{ Warning }{
The ALINE encoding scheme only accepts a single lower case character followed by one or more upper case characters. For example, "dD" can be accepted but "dd" can not.
}

\seealso{
\code{\link{encode.ALINE}}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.

