\name{ALINE.map}
\alias{ALINE.map}
\docType{data}
\title{
Aline IPA-ASCII character map
}
\description{
An IPA-ASCII character map used for transforming IPA sequence into ASCII characters used by the C++ program. ALINE.map() is used internally by various functions. The original mapping schema is defined in (Kondrak 1999). The values provided here were derived from an Indonesian database so additional user-mappings for use with other lanugauge families can be enabled. Unicode interger values are stored in the dataframe. To view IPA see show.map().
}
\usage{data(ALINE.map)}
\format{
  A data frame with 102 observations on the following 4 variables.
\describe{
    \item{\code{Aline}}{A column of ALINE symbols }
    \item{\code{U.Val}}{Unicode encoding for the IPA character.}
    \item{\code{A.Val}}{Unicode value(s) for the ALINE character(s).}
}
}
\examples{
data(ALINE.map)
}
\keyword{datasets}
\references{
Kondrak, G. (1999). Alignment of Phonetic Sequences. Technical Report CSRG-402. Department of Computer Science, University of Toronto. 
}
\seealso{
\code{\link{map}}
}
