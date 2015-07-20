\name{optimization.GA}
\alias{optimization.GA}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Core optimization function for finding optimal weights.
}
\description{
Cognate pairs and their determined alignment generated in ALINE format is used to find a set of optimal parameters in terms of number of correctly aligned pairs. A genetic algorithm is executed. It is called in the optimize.features function and is the core function for the optimization part.
}
\usage{
optimization.GA(Al, data, num, step = 5, plot = TRUE)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{Al}{
A 2*n matrix containing the correct alignment of the input
}
  \item{data}{
A 2*n matrix containing the pairs of words to be aligned
}
  \item{num}{
The size of initial population in the genetic algorithm
}
  \item{step}{
number of iterations for the genetic algorithm
}
  \item{plot}{
plot the convergence process of the algorithm
}
}

\value{
\item{R}{
a list, containing
}
\item{performance}{The number of correctly aligned pairs }
\item{optimized_parameters}{a matrix containing all the optimal parameters after the optimization}
}

\examples{
data<-as.matrix(data.frame(dog=c('dog','perro'),cat=c('cat','gato'),rat=c('rat','rata')))
M<-generate.training(raw.data=data,search.size=100,table=FALSE)
alignment<-rbind(M[[2]][4,],M[[2]][5,])
optimization.GA(Al=alignment,data=data,num=5,step=3,plot=FALSE)
}

\seealso{\code{\link{optimize.features}}}

% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
