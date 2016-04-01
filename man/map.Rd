\name{map}
\alias{map}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{User-defined Mappings}
\description{
Allows user-defined mappings from UTF-8 IPA to ASCII ALINE. User mappings are given precedence over defaults when duplicates exist. See notes for usage and allowable ASCII encodings.
}
\usage{
map(m1, m2)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{m1}{
a vector of IPA characters to encode.
}
\item{m2}{
a vector of ALINE encodings.
}
}


\value{
\item{map}{a dataframe with ALINE map that includes user-defined mappings.}
%% ...
}
\references{
Kondrak, G. (1999). Alignment of Phonetic Sequences. Technical Report CSRG-402. Department of Computer Science, University of Toronto. 
}
\author{
Sean Downey and Guowei Sun
}


\examples{
map(intToUtf8(418),"dX") #valid
map(intToUtf8(361),"dM") #invalid
map(intToUtf8(361),"dd") #invalid
}

\note{
Valid ASCII ALINE encodings are defined in Kondrak 1999, pp. 19. Allowable lowercase letters are ["a"-"z"] and allowable uppercase modifiers are: _D_ental, palato-al_V_olar, retrofle_X_, _P_alatal, _S_pirant, _N_asal, _A_spirated, lo_H_ng, _F_ront, _C_entral. If an IPA character is mapped to an invalid ASCII code a warning is issued and the mapping is not accepted.
}

\seealso{
\code{\link{ALINE.map}}
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.

