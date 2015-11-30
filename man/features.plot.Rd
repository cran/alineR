\name{features.plot}
\alias{features.plot}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Plot feature optimization result
}
\description{
Generates a 4x3 histogram panel plot using the optimization result from optimize.features.
}
\usage{
features.plot(R, 
          first = FALSE, 
          para = c(5, 40, 50, 10, 10, 10, 10, 5, 1, 5, 5, 5, 10),
          skip=FALSE,column=4,row=3)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{R}{
Output from optimize.features
}
  \item{first}{
If TRUE, plot only the first replicate. If FALSE, plot results from all independent replicates.  
}
  \item{para}{
The default feature weights to be plotted in the histogram.
}
\item{skip}{
If TRUE, inlcude a 13th histogram for the SkipCost parameter. 
}
\item{column}{
Number of parameter histogram plots in each row
}
\item{row}{
Number of parameter histogram plots in each column
}
}
\seealso{
\code{\link{generate.training},\link{optimize.features}}
}
\examples{
data<-data.frame(dog=c('dog','perro'),cat=c('cat','gato'),rat=c('rat','rata'))
M1<-generate.training(raw.data=data,search.size=100,table=FALSE)
M2<-optimize.features(set=M1,ranking=c(1,1,1),
                     num=20,step=5,replication=2,list=TRUE)
features.plot(M2)
}

\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
