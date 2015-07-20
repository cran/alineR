\name{optimize.features}
\alias{optimize.features}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Supervised learning with a genetic algorithm
}
\description{
Runs a genetic algorithm to find optimal parameter settings based on expert alignment determinations.
}
\usage{
optimize.features(set, ranking, num = 200, step = 45, replication = 5, 
    list = FALSE) 
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{set}{
the output from set.generation function, which is a two element list containing the original word pairs and possible alignments.
}
\item{ranking}{a vector specifying the correct alignment in the candidate alignments generated.}

\item{num}{number of populations in the genetic algorithm}

\item{step}{number of iterations in the genetic algorithm}

\item{replication}{number of independent genetic algorithm optimizations.}

\item{list}{Whether or not to return the entire result of the genetic algorithm which contains a big list of possible parameters and corresponding performance in each independent replication }

}
\value{

If list=FALSE, the function returns a single vector representing the optimal parameter values.

If list=TRUE, the function returns a list where each top-level element corresponds to the number of replications. Within each replicate, two elements are returned: 

\item{performance}{ Performance values for each population.}
\item{optimized_parameters}{ Feature values at each step in the optimization process.}
}

\examples{
# This simplified example illustrates the supervised learning workflow 
# some cognate data
data<-data.frame(dog=c('dog','perro'),cat=c('cat','gato'),rat=c('rat','rata'))

# generate training data for linguist (not written)
M1<-generate.training(raw.data=data, search.size=100)

# optimize features using expert determinations: 1,1,1
optimize.features(set=M1, ranking=c(1,1,1),
            num=20, step=5, replication=2, list=FALSE)

}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ Optimal Parameter }
\keyword{ Genetic Algorithm }% __ONLY ONE__ keyword per line
