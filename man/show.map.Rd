\name{show.map}
\alias{show.map}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
IPA-ASCII character map
}
\description{
Generating a dataframe containing the IPA and ASCII representation of the integer values stored in map.
}
\usage{
show.map()
}
\details{
CRAN policy specifies IPA characters cannot be stored in the dataframe ALINE.map. This function enables users to see the actual IPA characters and how they are mapped to ALINE encodings. 
}
\value{
A dataframe containing the following columns:
 \item{IPA }{IPA characters}
 \item{ALINE }{ALINE characters}
 \item{U.Val}{Integer values for the IPA characters}
 \item{A.Val}{Integer values for the ALINE characters}

}

\examples{
show.map()
}
